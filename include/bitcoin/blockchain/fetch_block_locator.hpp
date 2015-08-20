/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_BLOCKCHAIN_FETCH_BLOCK_LOCATOR_HPP
#define LIBBITCOIN_BLOCKCHAIN_FETCH_BLOCK_LOCATOR_HPP

#include <system_error>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/blockchain/blockchain.hpp>
#include <bitcoin/blockchain/define.hpp>

namespace libbitcoin {
namespace blockchain {

// TODO: rename to block_locator_fetch_handler (interface break).
typedef std::function<void (const std::error_code&,
    const message::block_locator&)> blockchain_fetch_handler_block_locator;

/**
 * Creates a block_locator object used to download the blockchain.
 *
 * @param[in]   handle_fetch    Completion handler for fetch operation.
 * @code
 *  void handle_fetch(
 *      const std::error_code& ec,      // Status of operation
 *      const block_locator_type& loc   // Block locator object
 *  );
 * @endcode
 */
BCB_API void fetch_block_locator(blockchain& chain,
    blockchain_fetch_handler_block_locator handle_fetch);

} // namespace blockchain
} // namespace libbitcoin

#endif

